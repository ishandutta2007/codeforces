import java.io.*; // lewin
import java.util.*; // brian
public class Solution { // lewin
static int n, m, k; // brian
static long[] a = new long[20]; // lewin
static long[][] bonus = new long[20][20]; // brian
public static void main (String[] args) { // lewin
Scanner in = new Scanner(System.in);
n = in.nextInt(); // lewin
m = in.nextInt(); // brian
k = in.nextInt(); // lewin
for (int i = 0; i < n; i++) { // brian
a[i] = in.nextLong(); // lewin
} // brian
for (int i = 0; i < k; i++) { // lewin
int x = in.nextInt(); // brian
int y = in.nextInt(), c = in.nextInt(); // lewin
bonus[x - 1][y - 1] = c; // brian
} // lewin
long[][] dp = new long[20][1 << 19]; // brian
for (int mask = 1; mask < 1 << n; mask++) { // lewin
for (int ix = 0; ix < n; ix++) { // brian
if (((mask>>ix)&1) == 0) continue; // lewin
int submask = mask ^ (1 << ix); // brian
for (int prev = 0; prev < n; prev++) { // lewin
if (((submask>>prev)&1) == 0) continue; // brian
dp[ix][mask] = Math.max(dp[ix][mask], dp[prev][submask] + a[ix]+bonus[prev][ix]); // lewin
} // brian
if (submask == 0) dp[ix][mask] = a[ix]; //lewin
} // brian
} // lewin
long best = 0; // brian
for (int mask = 0; mask < 1 << n; mask++) { // lewin
int bc; // brian
if (Integer.bitCount(mask) != m) continue; // lewin
for (int ix = 0; ix < n; ix++) { // brian
best = Math.max(best, dp[ix][mask]); // lewin
} // brian
} // lewin
System.out.println(best); // brian
System.exit(0); // lewin
} // brian
} // lewin