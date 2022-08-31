import java.util.*;
import java.io.*;
import java.math.BigInteger;

public final class Main
{
    private static final int MOD = 1000000007;

    private static final int[] readInts(BufferedReader in, int N) throws IOException
    {
        String line = in.readLine();
        int[] out = new int[N];
        if (line.equals(""))
            return out;
        String[] fields = line.split(" ");
        for (int i = 0; i < fields.length; i++)
            out[i] = Integer.parseInt(fields[i]);
        return out;
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        int[] a = readInts(in, N); a[N - 1] = 1;
        int[] b = readInts(in, N);
        BigInteger M = new BigInteger(in.readLine());
        int[] L = new int[N];
        int limit = 0;
        for (int i = 0; i < N - 1; i++)
        {
            limit = (limit + b[i]) / a[i];
            L[i + 1] = limit;
        }
        long[] r = new long[N];
        for (int i = 0; i < N - 1; i++)
        {
            if (a[i] > 1)
            {
                BigInteger[] divmod = M.divideAndRemainder(BigInteger.valueOf(a[i]));
                M = divmod[0];
                r[i] = divmod[1].longValue();
            }
        }
        try
        {
            r[N - 1] = M.longValueExact();
        }
        catch (ArithmeticException e)
        {
            r[N - 1] = Long.MAX_VALUE / 2;
        }
        r[N - 1] = Math.min(r[N - 1], Long.MAX_VALUE / 2);
        long[] dp = new long[1];
        dp[0] = 1;
        for (int i = N - 1; i >= 0; i--)
        {
            long[] acc = new long[dp.length + 1];
            for (int j = 0; j < dp.length; j++)
                acc[j + 1] = acc[j] + dp[j];
            long scale = a[i];
            long[] dp2 = new long[L[i] + 1];
            for (int j = 0; j <= L[i]; j++)
            {
                int klo = (int) (Math.max(j - r[i] + scale - 1, 0) / scale);
                if (b[i] + j - r[i] < 0)
                    continue;
                int khi = (int) Math.min((b[i] + j - r[i]) / scale + 1, dp.length);
                if (klo < khi)
                    dp2[j] = (acc[khi] - acc[klo]) % MOD;
            }
            dp = dp2;
        }
        System.out.println(dp[0]);
    }
}