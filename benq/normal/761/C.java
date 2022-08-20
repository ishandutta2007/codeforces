import java.util.*;
import java.io.*;


public class Main {
    static int n;
    static int m;
    static int[][][][][]dp;
    static int ans;
    static String[]s;
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        OutputWriter out = new OutputWriter(System.out);
         n = in.nextInt();
         m = in.nextInt();
         dp = new int[n][2][2][2][5001];
         ans=Integer.MAX_VALUE;
         s = new String[n];
         for (int i =0;i<n;i++)
             s[i]=in.readString();
         for (int i =0;i<n;i++)
             for (int i1=0;i1<2;i1++)
                 for (int i2=0;i2<2;i2++)
                     for (int i3=0;i3<2;i3++)
                         for (int i4=0;i4<5001;i4++)
                         dp[i][i1][i2][i3][i4]=-1;
         out.printLine(solve(0,0,0,0,0,dp));
        out.flush();
    }
  static int solve(int index,int a,int b,int c,int min,int[][][][][]dp)
  {
      if (index==n)
      {
          if (a>0&&b>0&&c>0)
          return min;
          else
              return 1000;
      }
     if (dp[index][a][b][c][min]>-1)
         return dp[index][a][b][c][min];
   int res=1000;
      for (int i =0;i<m;i++)
      {
          if (s[index].charAt(i)>='0'&&s[index].charAt(i)<='9')
          {
            res= Math.min(solve(index+1,Math.min(1,a+1),b,c,min+Math.min(i,m-i),dp),res);
          }
          if (s[index].charAt(i)=='#'||s[index].charAt(i)== '*'||s[index].charAt(i)== '&')
          {
              res= Math.min(solve(index+1,a,b,Math.min(1,c+1),min+Math.min(i,m-i),dp),res);
          }
          if (s[index].charAt(i)>='a'&&s[index].charAt(i)<='z')
          {
              res= Math.min(solve(index+1,a,Math.min(1,b+1),c,min+Math.min(i,m-i),dp),res);
          }
      }
      dp[index][a][b][c][min]=res;
      return dp[index][a][b][c][min];
  }
}


class pair  implements Comparable
{

    int key;
    int value;
    public pair(Object key, Object value) {

        this.key = (int)key;
        this.value=(int)value;
    }

    @Override
    public int compareTo(Object o) {
        pair temp =(pair)o;
        return  key-temp.key;
    }
}
class Graph {


    int n;
    ArrayList<Integer>[] adjList;

    public Graph(int n) {
        this.n = n;
        adjList = new ArrayList[n];
        for (int i = 0; i < n; i++)
            adjList[i] = new ArrayList<>();
    }

}


class InputReader {

    private final InputStream stream;
    private final byte[] buf = new byte[8192];
    private int curChar, snumChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (snumChars == -1)
            throw new InputMismatchException();
        if (curChar >= snumChars) {
            curChar = 0;
            try {
                snumChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (snumChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int nextInt() {
        int c = read();
        while (isSpaceChar(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public long nextLong() {
        int c = read();
        while (isSpaceChar(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public int[] nextIntArray(int n) {
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        return a;
    }

    public String readString() {
        int c = read();
        while (isSpaceChar(c)) {
            c = read();
        }
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public String nextLine() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isEndOfLine(c));
        return res.toString();
    }

    public boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private boolean isEndOfLine(int c) {
        return c == '\n' || c == '\r' || c == -1;
    }

}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }


    public void printLine(Object... objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

    public void flush() {
        writer.flush();
    }

}