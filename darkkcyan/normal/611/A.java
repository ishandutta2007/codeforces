import java.io.*;
import java.io.IOException;
import java.util.*;

public class main {
	public static class FReader {
		public static BufferedReader reader;
		public static StringTokenizer tokenizer;

		public static void init (InputStream in) {
			reader = new BufferedReader(new InputStreamReader(in));
			tokenizer = new StringTokenizer("");
		}

		public static String next () throws IOException {
			if (!tokenizer.hasMoreTokens()) {
				tokenizer = new StringTokenizer(reader.readLine());
			}
			return tokenizer.nextToken();
		}

		public static int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
	}

	public static void main (String[] args) { try {
		FReader.init(System.in);

		int num = FReader.nextInt();
		FReader.next();
		String str = FReader.next();

		// System.out.println("\"" + str + "\"");

		if (str.equals("week")) {
			 if (num <= 4 || num == 7) {
				System.out.println(52);
			} else {
				System.out.println(53);
			}
		} else {
			if (num <= 29) {
				System.out.println(12);
			} else if (num == 30) {
				System.out.println(11);
			} else if (num == 31) {
				System.out.println(7);
			}
		}

	} catch(Exception e) {} }
}