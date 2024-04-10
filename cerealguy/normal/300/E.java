import static java.lang.Math.max;

import java.io.*;

public class E {

    static void solve() throws IOException {
        int k = nextInt();
        int[] a = new int[k];
        for (int i = 0; i < k; i++) {
            a[i] = nextInt();
        }

        int maxValue = 0;
        for (int value : a) {
            maxValue = max(maxValue, value);
        }
        int[] primes = calcP(maxValue + 1);

        int[] count = new int[maxValue + 1];
        for (int value : a) {
            ++count[value];
        }
        for (int i = maxValue; i > 0; --i) {
            count[i - 1] += count[i];
        }


        long minN = 0;
        long sum = sum(a);
        long maxN = minN + 1;

        for (int primeIndex = 0; primeIndex < primes.length; ++primeIndex) {
            int prime = primes[primeIndex];
            long deg = degInFact(prime, count);
            if (!largeEnough(maxN / prime, prime, deg)) {
                maxN = sum / prime;
                minN = minN / prime;
                while (maxN > minN + 1) {
                    long midN = maxN + minN >>> 1;
                    if (largeEnough(midN, prime, deg)) {
                        maxN = midN;
                    } else {
                        minN = midN;
                    }
                }
                maxN *= prime;
                minN = maxN - 1;
            }
        }

        System.out.println(maxN);
    }

    static long degInFact(int prime, int[] count) {
        long sum = 0;
        int curVal = prime;
        while (true) {
            for (int i = curVal; i < count.length; i += curVal) {
                sum += count[i];
            }
            long next = (long) curVal * prime;
            if (next >= count.length) {
                break;
            }
            curVal = (int) next;
        }
        return sum;
    }

    private static boolean largeEnough(long checkN, int prime, long pow) {
        for (; checkN > 0; checkN /= prime) {
            pow -= checkN;
            if (pow <= 0) {
                return true;
            }
        }
        return false;
    }

    private static long sum(int[] a) {
        long s = 0;
        for (int value : a) {
            s += value;
        }
        return s;
    }

    static int[] calcP(int max) {
        if (max <= 2) {
            return new int[0];
        }
        boolean[] notPrime = new boolean[max >>> 1];
        notPrime[0] = true;
        for (int val = 1; val * val < max; val += 2) {
            if (!notPrime[val >>> 1]) {
                for (int j = val * val; j < max; j += 2 * val) {
                    notPrime[j >>> 1] = true;
                }
            }
        }
        int cnt = 1;
        for (int i = 0; i < notPrime.length; i++) {
            if (!notPrime[i])
                cnt++;
        }
        int[] p = new int[cnt];
        cnt = 0;
        p[cnt++] = 2;
        for (int i = 0; i < notPrime.length; i++) {
            if (!notPrime[i])
                p[cnt++] = 2 * i + 1;
        }
        return p;
    }

    static BufferedReader br;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        File file = new File("e.in");
        if (file.exists() && file.canRead()) {
            input = new FileInputStream(file);
        }
        br = new BufferedReader(new InputStreamReader(input));
        solve();
    }

    static int nextInt() throws IOException {
        int c = br.read();
        while (c < '0' || c > '9') {
            c = br.read();
        }
        int ret = 0;
        while (c >= '0' && c <= '9') {
            ret = ret * 10 + c - '0';
            c = br.read();
        }
        return ret;
    }
}