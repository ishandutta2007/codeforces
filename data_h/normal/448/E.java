import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;



public class Main {
	Scanner in = new Scanner(System.in);
	int total = 0;
	final int LIMIT = 100000;
	ArrayList<Long> list = new ArrayList<Long>(); 
	
	void dfs(long n, long k) {
		if (total == LIMIT)
			return ;
		if (n == 1 || k == 0) {
			System.out.print(n + " ");
			total++;
			return ;
		}
		for(int i = 0; i < list.size() && list.get(i) <= n; i++) {
			if (n % list.get(i) == 0) {
				dfs(list.get(i), k - 1);
			}
		}
	}
	
	void run() {
		long n = in.nextLong(), k = in.nextLong();
		for(long i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				list.add(i);
				if (i * i != n) {
					list.add(n / i);
				}
			}
		}
		Collections.sort(list);
		dfs(n, k);
	}
	
	public static void main(String args[]) {
		new Main().run();
	}
}