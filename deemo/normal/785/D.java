import java.util.*;

public class D{
	int pw(int a, int b, int MOD){
		int ret = 1;
		while (b>0){
			if ((b & 1)==1)
				ret = (int)(1L * ret * a % MOD);
			b >>= 1;
			a = (int)(1L * a * a % MOD);
		}
		return ret;
	}
	public static void main(String[] argc){
		Scanner sc = new Scanner(System.in);
		D sol = new D();
		String s = sc.next();
		final int MAXN = (int)2e5 + 10, MOD = (int)1e9 + 7;
		int[] ss = new int[MAXN], tt = new int[MAXN];
		ss[0] = 1;
		for (int i = 1; i < MAXN; i++)
			ss[i] = (int)(1L * ss[i - 1] * i % MOD);
		tt[0] = 1;
		for (int i = 1; i < MAXN; i++)
			tt[i] = (int)(1L * tt[i-1] * sol.pw(i, MOD-2, MOD) % MOD);

		int ans=0, c1 = 0, c2 = 0;
		for (char c:s.toCharArray())
			if (c == ')') c2++;

		for (char c:s.toCharArray())
			if (c == '('){
				c1++;
				if (c2>0)
					ans = (int)((ans + 1L * ss[c1 + c2 - 1] * tt[c1] % MOD * tt[c2 - 1]) % MOD);
			}
			else c2--;
			
		System.out.println(ans);
	}
}