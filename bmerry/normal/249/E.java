import java.util.*;
import java.math.BigInteger;

public class E
{
    private static BigInteger sums(long x)
    {
        if (x % 2 == 0)
            return BigInteger.valueOf(x / 2).multiply(BigInteger.valueOf(x + 1));
        else
            return BigInteger.valueOf(x).multiply(BigInteger.valueOf((x + 1) / 2));
    }

    private static BigInteger sumssq(long x)
    {
        return sums(x * x);
    }

    private static BigInteger sums2(long x)
    {
        long x1 = x + 1;
        long x2 = 2 * x + 1;
        if (x % 3 == 0)
            x /= 3;
        else if (x1 % 3 == 0)
            x1 /= 3;
        else
            x2 /= 3;
        if (x % 2 == 0)
            x /= 2;
        else
            x1 /= 2;
        return BigInteger.valueOf(x).multiply(BigInteger.valueOf(x1)).multiply(BigInteger.valueOf(x2));
    }

    static BigInteger cum(long r, long c)
    {
        if (r == 0 || c == 0)
            return BigInteger.ZERO;
        BigInteger R = BigInteger.valueOf(r);
        BigInteger C = BigInteger.valueOf(c);
        if (c >= r)
        {
            long d = c - r;
            BigInteger D = BigInteger.valueOf(d);
            BigInteger sq = sumssq(r);
            BigInteger rm1 = R.subtract(BigInteger.ONE);
            BigInteger row = D.multiply(rm1.multiply(rm1).add(BigInteger.ONE))
                .add(D.multiply(D.add(BigInteger.ONE)).multiply(rm1))
                .add(sums2(d));
            BigInteger ans = sq.add(row.multiply(R)).add(D.multiply(sums(r - 1)));
            return ans;
        }
        else
        {
            long d = r - c;
            BigInteger D = BigInteger.valueOf(d);
            BigInteger sq = sumssq(c);
            BigInteger col = D.multiply(C.multiply(C))
                .add(D.multiply(D.add(BigInteger.ONE)).multiply(C))
                .add(sums2(d));
            BigInteger ans = sq.add(col.multiply(C)).subtract(D.multiply(sums(c - 1)));
            return ans;
        }
    }

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int i = 0; i < T; i++)
        {
            long x1, y1, x2, y2;
            x1 = in.nextInt(); x1--;
            y1 = in.nextInt(); y1--;
            x2 = in.nextInt();
            y2 = in.nextInt();

            BigInteger ans = cum(x2, y2).add(cum(x1, y1)).subtract(cum(x1, y2)).subtract(cum(x2, y1));
            BigInteger radix = BigInteger.valueOf(10000000000L);
            if (ans.compareTo(radix) >= 0)
            {
                String v = ans.toString();
                System.out.println("..." + v.substring(v.length() - 10));
            }
            else
                System.out.println(ans);
        }
    }
}