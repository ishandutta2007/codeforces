import java.util.Scanner;


public class Main {
	
	public static long solve(int n, int m, long val) {
		long result = 0;
		for(int i = 1, r = m; i <= n; i++) {
			while(1L * i * r > val)
				r--;
			result += r;
		}
		return result;
	}
	
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int m = input.nextInt();
		long k = input.nextLong();
		long l = 1, r = 1L * n * m;
		while(l < r) {
			long mid = ((l + r) >> 1);
			//System.out.println(mid + " = " + solve(n, m, mid));
			if (solve(n, m, mid) < k) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		System.out.println(l);
	}
}