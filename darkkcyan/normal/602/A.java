import java.math.BigInteger;
import java.util.Scanner;

public class main {
	static class MyNum {
		int numberOfDigits;
		int base;
		BigInteger result;

		void read(Scanner in) {
			numberOfDigits = in.nextInt();
			base = in.nextInt();

			int digits[] = new int[numberOfDigits];

			for (int i = 0; i < numberOfDigits; ++i) {
				digits[i] = in.nextInt();
			}

			BigInteger t = BigInteger.ONE;
			BigInteger b = BigInteger.valueOf(base);
			result = BigInteger.ZERO;
			for (int i = numberOfDigits - 1; i >= 0; --i) {
				result = result.add(
					BigInteger.valueOf(digits[i]).multiply(t)
				);

				t = t.multiply(b);
			}
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		MyNum x = new MyNum();
		MyNum y = new MyNum();
		x.read(in);
		y.read(in);

		int result = x.result.compareTo(y.result);
		if (result < 0) System.out.println("<");
		else if (result > 0) System.out.println(">");
		else System.out.println("=");
	}
}