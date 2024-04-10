import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.IOException;
public class Main {
	final static int MAXN = 200010;
	static int n;
	static long K;
	final static long ranl = -200000000000000L, ranr = 200000000000000L;
	public static class node {
		node ls, rs;
		int v;
		node() { ls = rs = null; v = 0; }
	}
	public static node modify(node u, long l, long r, long tar) {
		if (u == null) u = new node();
		if (l == r) { ++u.v; return u; }
		long mid = l + r >> 1;
		if (tar <= mid) u.ls = modify(u.ls, l, mid, tar);
		else u.rs = modify(u.rs, mid + 1, r, tar);
		u.v = 0;
		if (u.ls != null) u.v += u.ls.v;
		if (u.rs != null) u.v += u.rs.v;
		return u;
	}
	public static int query(node u, long l, long r, long L, long R) {
		if (u == null) return 0;
		if (L <= l && r <= R) return u.v;
		long mid = l + r >> 1;
		int res = 0;
		if (L <= mid) res += query(u.ls, l, mid, L, R);
		if (mid < R) res += query(u.rs, mid + 1, r, L, R);
		return res;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String [] pt = br.readLine().split(" ");
		n = Integer.parseInt(pt[0]);
		K = Long.parseLong(pt[1]);
		pt = br.readLine().split(" ");
		long pre = 0, ans = 0;
		node rt = new node();
		modify(rt, ranl, ranr, 0);
		for (int i = 0; i < n; ++i) {
			pre = pre + Integer.parseInt(pt[i]); 
			long vt = pre - K + 1;
			if (vt < ranl) vt = ranl;
			ans += query(rt, ranl, ranr, vt, ranr);
			modify(rt, ranl, ranr, pre);
			// System.out.println(pre + " " + vt);
		}
		System.out.println(ans);
	}

}