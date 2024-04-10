import java.util.Scanner;


public class Main {
	final int N = 5555, INF = 1111111111;
	int[] a = new int[N];
	Scanner input = new Scanner(System.in);
	int n;
	
	int dfs(int l, int r, int base) {
		int minH = INF;
		for(int i = l; i <= r; i++) {
			if (a[i] < minH) {
				minH = a[i];
			}
		}
		int result = minH - base;
		for(int i = l, j = l; i <= r; i = j) {
			if (a[i] > minH) {
				for(j = i; j <= r && a[j] > minH; j++);
				result += dfs(i,  j - 1, minH);
			} else {
				j = i + 1;
			}
		}
		return Math.min(r - l + 1, result);
	}
	
	void run() {
		n = input.nextInt();
		for(int i = 0; i < n; i++) {
			a[i] = input.nextInt();
		}
		System.out.println(dfs(0, n - 1, 0));
	}
	
	public static void main(String args[]) {
		new Main().run();
	}
}