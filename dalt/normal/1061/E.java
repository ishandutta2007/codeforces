import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 27);
        thread.start();
        thread.join();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            EPolitics solver = new EPolitics();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EPolitics {
        LinearProgramming.DualLinearProgramming dlp;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int x = in.readInt();
            int y = in.readInt();

            int[] income = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                income[i] = in.readInt();
            }

            EPolitics.Node[] a = new EPolitics.Node[n + 1];
            EPolitics.Node[] b = new EPolitics.Node[n + 1];

            for (int i = 1; i <= n; i++) {
                a[i] = new EPolitics.Node();
                b[i] = new EPolitics.Node();
                a[i].id = b[i].id = i;
            }

            for (int i = 1; i < n; i++) {
                EPolitics.Node u = a[in.readInt()];
                EPolitics.Node v = a[in.readInt()];
                u.next.add(v);
                v.next.add(u);
            }

            for (int i = 1; i < n; i++) {
                EPolitics.Node u = b[in.readInt()];
                EPolitics.Node v = b[in.readInt()];
                u.next.add(v);
                v.next.add(u);
            }

            dfsForParent(a[x], null);
            dfsForParent(b[y], null);

            int q1 = in.readInt();
            int[][] constrains1 = new int[q1][2];
            for (int i = 0; i < q1; i++) {
                for (int j = 0; j < 2; j++) {
                    constrains1[i][j] = in.readInt();
                }
                SequenceUtils.swap(constrains1[i], 0, 1);
            }

            int q2 = in.readInt();
            int[][] constrains2 = new int[q2][2];
            for (int i = 0; i < q2; i++) {
                for (int j = 0; j < 2; j++) {
                    constrains2[i][j] = in.readInt();
                }
                SequenceUtils.swap(constrains2[i], 0, 1);
            }

            dlp = new LinearProgramming.DualLinearProgramming(2 * q1 + 2 * q2 + n, n, 1e-8);

            for (int i = 1; i <= n; i++) {
                dlp.setTargetCoefficient(i, -income[i]);
            }

            int constraintIndex = 1;
            for (int i = 0; i < q1; i++, constraintIndex += 2) {
                dlp.setConstraintConstant(constraintIndex, constrains1[i][0]);
                dlp.setConstraintConstant(constraintIndex + 1, -constrains1[i][0]);
                dfsForConstraint(constraintIndex, constraintIndex + 1, a[constrains1[i][1]]);
            }

            for (int i = 0; i < q2; i++, constraintIndex += 2) {
                dlp.setConstraintConstant(constraintIndex, constrains2[i][0]);
                dlp.setConstraintConstant(constraintIndex + 1, -constrains2[i][0]);
                dfsForConstraint(constraintIndex, constraintIndex + 1, b[constrains2[i][1]]);
            }

            for (int i = 1; i <= n; i++, constraintIndex += 1) {
                dlp.setConstraintConstant(constraintIndex, -1);
                //dlp.setConstraintConstant(constraintIndex + 1, 0);
                dlp.setConstraintCoefficient(constraintIndex, i, -1);
                //dlp.setConstraintCoefficient(constraintIndex + 1, i, -1);
            }

            dlp.solve();
            if (dlp.isInfeasible()) {
                out.println(-1);
                return;
            }

            out.println(DigitUtils.round(-dlp.minSolution()));
        }

        public void dfsForParent(EPolitics.Node root, EPolitics.Node p) {
            root.p = p;
            for (EPolitics.Node node : root.next) {
                if (node == p) {
                    continue;
                }
                dfsForParent(node, root);
            }
        }

        public void dfsForConstraint(int i, int j, EPolitics.Node root) {
            dlp.setConstraintCoefficient(i, root.id, 1);
            dlp.setConstraintCoefficient(j, root.id, -1);

            for (EPolitics.Node node : root.next) {
                if (node == root.p) {
                    continue;
                }
                dfsForConstraint(i, j, node);
            }
        }

        static class Node {
            EPolitics.Node p;
            List<EPolitics.Node> next = new ArrayList<>();
            int id;

        }

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastInput(InputStream is) {
            this.is = is;
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    bufLen = -1;
                }
                if (bufLen == -1) {
                    return -1;
                }
            }
            return buf[bufOffset++];
        }

        public void skipBlank() {
            while (next >= 0 && next <= 32) {
                next = read();
            }
        }

        public int readInt() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            int val = 0;
            if (sign == 1) {
                while (next >= '0' && next <= '9') {
                    val = val * 10 + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = val * 10 - next + '0';
                    next = read();
                }
            }

            return val;
        }

    }

    static class LinearProgramming {
        private final double PREC;
        private final double INF = 1e50;
        double[][] mat;
        int[] basicVariables;
        int[] basicVariable2RowIndex;
        boolean unbound;
        boolean infeasible;
        int n;
        int m;

        public LinearProgramming(int n, int m, double prec) {
            this.PREC = prec;
            this.n = n;
            this.m = m + n;
            mat = new double[n + 1][this.m + 2];
            basicVariables = new int[this.m + 2];
            basicVariable2RowIndex = new int[this.m + 2];
            for (int i = 1; i <= this.m; i++) {
                if (i <= m) {
                    basicVariable2RowIndex[i] = -1;
                } else {
                    basicVariable2RowIndex[i] = i - m;
                    basicVariables[i - m] = i;
                }
            }
        }

        public void setConstraintConstant(int constraintId, double noMoreThan) {
            mat[constraintId][0] = noMoreThan;
        }

        public void setConstraintCoefficient(int constraintId, int variableId, double c) {
            mat[constraintId][variableId] = -c;
        }

        public void setTargetCoefficient(int variableId, double c) {
            mat[0][variableId] = c;
        }

        public double maxSolution() {
            return mat[0][0];
        }

        public boolean isUnbound() {
            return unbound;
        }

        private boolean initSimplex() {
            if (n == 0) {
                return true;
            }
            int minConstantRow = 1;
            for (int i = 2; i <= n; i++) {
                if (mat[i][0] < mat[minConstantRow][0]) {
                    minConstantRow = i;
                }
            }
            if (mat[minConstantRow][0] >= 0) {
                return true;
            }
            double[] originalTargetExpression = mat[0];
            m++;
            mat[0] = new double[m + 1];
            mat[0][m] = -1;
            basicVariable2RowIndex[m] = -1;
            for (int i = 1; i <= n; i++) {
                mat[i][m] = 1;
            }
            pivot(m, minConstantRow);
            while (simplex()) ;
            if (mat[0][0] != 0 || unbound) {
                infeasible = true;
                unbound = false;
                return false;
            }
            if (basicVariable2RowIndex[m] != -1) {
                int row = basicVariable2RowIndex[m];
                int firstNegativeVariable = -1;
                for (int i = 1; i <= m && firstNegativeVariable == -1; i++) {
                    if (mat[row][i] != 0) {
                        firstNegativeVariable = i;
                    }
                }
                pivot(firstNegativeVariable, row);
            }

            //restore
            m--;
            mat[0] = originalTargetExpression;
            for (int i = 1; i <= m; i++) {
                if (basicVariable2RowIndex[i] == -1) {
                    continue;
                }
                int row = basicVariable2RowIndex[i];
                double c = mat[0][i];
                for (int j = 0; j <= m; j++) {
                    if (j == i) {
                        mat[0][j] = 0;
                        continue;
                    }
                    mat[0][j] += mat[row][j] * c;
                }
            }
            normalize();
            return true;
        }

        public void solve() {
            if (!initSimplex()) {
                return;
            }
            while (simplex()) ;
        }

        private void normalize() {
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= m; j++) {
                    if (mat[i][j] >= -PREC && mat[i][j] <= PREC) {
                        mat[i][j] = 0;
                    }
                }
            }
        }

        private void pivot(int variableId, int row) {
            int basicVariableId = basicVariables[row];
            mat[row][basicVariableId] = -1;
            for (int i = 0; i <= m; i++) {
                if (i == variableId) {
                    continue;
                }
                mat[row][i] /= -mat[row][variableId];
            }
            mat[row][variableId] = -1;
            basicVariables[row] = variableId;
            basicVariable2RowIndex[basicVariableId] = -1;
            basicVariable2RowIndex[variableId] = row;
            for (int i = 0; i <= n; i++) {
                if (i == row || mat[i][variableId] == 0) {
                    continue;
                }
                double c = mat[i][variableId];
                for (int j = 0; j <= m; j++) {
                    if (j == variableId) {
                        mat[i][j] = 0;
                        continue;
                    }
                    mat[i][j] += mat[row][j] * c;
                }
            }
            normalize();
        }

        private boolean simplex() {
            int firstPositiveVariableId = -1;
            for (int i = 1; i <= m && firstPositiveVariableId == -1; i++) {
                if (mat[0][i] > 0) {
                    firstPositiveVariableId = i;
                }
            }
            if (firstPositiveVariableId == -1) {
                return false;
            }
            double maxConstraint = INF;
            int maxConstraintRow = -1;
            for (int i = 1; i <= n; i++) {
                if (mat[i][firstPositiveVariableId] >= 0) {
                    continue;
                }
                double constraint = mat[i][0] / (-mat[i][firstPositiveVariableId]);
                if (maxConstraint > constraint) {
                    maxConstraint = constraint;
                    maxConstraintRow = i;
                }
            }
            if (maxConstraintRow == -1) {
                unbound = true;
                return false;
            }
            pivot(firstPositiveVariableId, maxConstraintRow);
            return true;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            builder.append("Maximize\n  ").append(mat[0][0]);
            for (int i = 1; i <= m; i++) {
                if (mat[0][i] == 0) {
                    continue;
                }
                builder.append("+").append(mat[0][i]).append("x").append(i);
            }
            builder.append("\n").append("Constraints\n");
            for (int i = 1; i <= n; i++) {
                builder.append("  ");
                for (int j = 1; j <= m; j++) {
                    if (mat[i][j] == 0) {
                        continue;
                    }
                    builder.append(-mat[i][j]).append("x").append(j).append("+");
                }
                if (builder.length() > 0 && builder.charAt(builder.length() - 1) == '+') {
                    builder.setLength(builder.length() - 1);
                }
                builder.append("<=").append(mat[i][0]).append("\n");
            }
            return builder.toString();
        }

        public static class DualLinearProgramming {
            LinearProgramming lp;
            int n;
            int m;

            public DualLinearProgramming(int n, int m, double prec) {
                this.n = n;
                this.m = m;
                lp = new LinearProgramming(m, n, prec);
            }

            public void setConstraintConstant(int constraintId, double noMoreThan) {
                lp.setTargetCoefficient(constraintId, noMoreThan);
            }

            public void setConstraintCoefficient(int constraintId, int variableId, double c) {
                lp.setConstraintCoefficient(variableId, constraintId, c);
            }

            public void setTargetCoefficient(int variableId, double c) {
                lp.setConstraintConstant(variableId, c);
            }

            public void solve() {
                lp.solve();
            }

            public double minSolution() {
                return lp.maxSolution();
            }

            public boolean isInfeasible() {
                return lp.isUnbound();
            }

            public double getAssignmentValueForVariable(int i) {
                if (i + n <= lp.m) {
                    return -lp.mat[0][i + n];
                } else {
                    return 0;
                }
            }

            public String toString() {
                StringBuilder builder = new StringBuilder();
                for (int i = 1; i <= m; i++) {
                    double val = getAssignmentValueForVariable(i);
                    builder.append("x").append(i).append("=").append(val).append('\n');
                }
                builder.append("min=").append(minSolution());
                return builder.toString();
            }

        }

    }

    static class SequenceUtils {
        public static void swap(int[] data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

    }

    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput println(int c) {
            cache.append(c).append('\n');
            return this;
        }

        public FastOutput println(long c) {
            cache.append(c).append('\n');
            return this;
        }

        public FastOutput flush() {
            try {
                os.append(cache);
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                os.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static long round(double x) {
            if (x >= 0) {
                return (long) (x + 0.5);
            } else {
                return (long) (x - 0.5);
            }
        }

    }
}