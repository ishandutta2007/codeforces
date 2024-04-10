
import java.util.*;
import java.math.*;

public class A {
	static int inf = (1 << 30); 
	public static void main(String arg[]) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int[] a = new int[4], b = new int[4], c = new int[4], d = new int[4];
		Pair[] p = new Pair[4];
		
		int leastMoney = inf, position = -1;
		for(int i = 0; i < 4; i++) {
			a[i] = input.nextInt();
			b[i] = input.nextInt();
			c[i] = input.nextInt();
			d[i] = input.nextInt();
			p[i] = new Pair(Math.min(a[i], b[i]), Math.min(c[i], d[i]));
			if (p[i].first + p[i].second < leastMoney) {
				leastMoney = p[i].first + p[i].second;
				position = i;
			}
		}
		if (leastMoney > n) {
			System.out.println(-1);
		} else {
			System.out.println((position + 1) + " " + p[position].first +
					" " + (n - p[position].first));
		}
	}
}

class Pair {
	int first, second;
	Pair(int a, int b) {
		first = a;
		second = b;
	}
};