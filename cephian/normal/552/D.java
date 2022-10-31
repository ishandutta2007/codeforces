import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {

	static int gcd(int a, int b) {
		return (b == 0) ? a : gcd(b, a % b);
	}

	static long choose3(long n) {
		return (n * (n - 1) * (n - 2)) / 6;
	}

	static long choose2(long n) {
		return (n * (n - 1)) / 2;
	}

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		int[] x = new int[n], y = new int[n];
		long ans = 3 * choose3(n);
		for (int i = 0; i < n; ++i) {
			String tmp[] = br.readLine().split(" ");
			x[i] = Integer.parseInt(tmp[0]);
			y[i] = Integer.parseInt(tmp[1]);
		}

		for (int i = 0; i < n; ++i) {
			HashMap<Point, Integer> h = new HashMap<Point, Integer>();
			for (int j = 0; j < n; ++j) {
				if (i == j)
					continue;
				int x2 = x[j] - x[i], y2 = y[j] - y[i];

				if (y2 < 0) {
					x2 = -x2;
					y2 = -y2;
				}
				
				if (x2 == 0)
					y2 = 1;
				else if (y2 == 0)
					x2 = 1;
				else {
					int g = gcd(Math.abs(x2), Math.abs(y2));
					x2 /= g;
					y2 /= g;
				}
				Point p = new Point(x2, y2);
				if (h.containsKey(p)) {
					h.put(p, h.get(p) + 1);
				} else
					h.put(p, 1);
			}
			for (Point p : h.keySet()) {
				if (h.get(p) > 1) {
					ans -= choose2(h.get(p));
				}
			}
		}
		System.out.println(ans / 3);
	}
}