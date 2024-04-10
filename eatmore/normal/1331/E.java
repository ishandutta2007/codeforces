import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static final long DATA[] = {0x2fd4000000L, 0x3e957400000L, 0x90b11700000L, 0x5d787d5e0000L, 0xd50f05030000L, 0x291a5ddf64000L, 0x6db3c5024e000L, 0x1c4987776df800L, 0x396cd1043ffc00L, 0x7fe79fdffffe00L, 0xffffffffffff00L, 0x1ffffffffffff80L, 0x1ffffffffffff80L, 0x3ffffffffffffc0L, 0x7ffffffffffffe0L, 0x7ffffffffffffe0L, 0xffffffffffffff0L, 0x1ffffffffffffff8L, 0x1fffffffffffffe0L, 0x7ffd47ffe47ff80L, 0xff017fff13fe0cL, 0x301a6dfffc58f83cL, 0x7e00c4bff9ce20feL, 0x7fc27dbfe36483feL, 0x7ff7091fce0edffeL, 0x7fa45f5fe3b883feL, 0xff8ec24fc892efffL, 0xffa39eebddda47ffL, 0xffb8f4a1487bf7ffL, 0xff9225b51dc907ffL, 0xffdfaf07476f6fffL, 0xff88e9ee5c49c7ffL, 0xffa26c8376ec1fffL, 0xfff6c5a94285bfffL, 0xffe39d2deaaf0fffL, 0xfff8c86478e25fffL, 0xfff25d36da38ffffL, 0xffff11fc1fa3ffffL, 0x7ffe47ff5f09fffeL, 0x7ffffff87ffffffeL, 0x7ffffffd2ffffffeL, 0x7fffffff8bfffffeL, 0x3ffffffe23fffffcL, 0x3fffffffbffff9fcL, 0x1fdfffff1fffebf8L, 0x1f85f7ff4ffe23f8L, 0x1fd0634a6b14abf8L, 0xff72818c0418ff0L, 0x7fd7dc39def2fe0L, 0x7fc416ef4497fe0L, 0x3ff170a216c3fc0L, 0x1fff1a2b7c6ff80L, 0x1ffc4e8e29cff80L, 0xfff7bdb8f1ff00L, 0x7ffe840a1bfe00L, 0x3ffcd6debffc00L, 0x1ffe10f0fff800L, 0x7fffdffffe000L, 0x3ffffffffc000L, 0xffffffff0000L, 0x7ffffffe0000L, 0xffffff00000L, 0x3ffffc00000L, 0x3ffc000000L};

	static void solve() throws Exception {
		int i = scanInt(), j = scanInt();
		out.print((DATA[i] & (1L << j)) != 0 ? "IN" : "OUT");
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}