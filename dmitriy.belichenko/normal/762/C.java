import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.*;
public class Main {

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		String s = in.next(), t = in.next();
		char[] a = s.toCharArray(), b = t.toCharArray();
		int[] pre = compute(a, b);
		rev(a);
		rev(b);
		int[] suf = compute(a, b);
		int max = 0, l = -1, r = -1;
		for(int i = 0, j = b.length - 1; i < b.length; ++i)
		{
			if(pre[i] == -1)
				break;
			while(j >= 0 && (i + j + 2 > b.length || suf[j] == -1 || a.length - suf[j] - 1 <= pre[i]))
				--j;
			if(j == -1)
				break;

			int cur = i + j + 2;
			if(cur > max)
			{
				max = cur;
				l = i + 1;
				r = j + 1;
			}

		}
		for(int i = 0; i < b.length; ++i)
		{
			if(pre[i] != -1 && i + 1 > max)
			{
				max = i + 1;
				l = i + 1;
				r = 0;
			}

			if(suf[i] != -1 && i + 1 > max)
			{
				max = i + 1;
				r = i + 1;
				l = 0;
			}
		}
		if(max == 0)
			out.println("-");
		else
			out.println(t.substring(0, l) + t.substring(t.length() - r));
		out.flush();
		out.close();
	}

	static void rev(char[] s)
	{
		for(int i = 0, j = s.length - 1; i < j; ++i, --j)
		{
			char tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;
		}
	}
	static int[] compute(char[] a, char[] b)
	{
		int i = 0, j = 0;
		int[] ret = new int[b.length];
		Arrays.fill(ret, -1);
		while(i < a.length && j < b.length)
		{
			if(a[i] == b[j])
				ret[j++] = i;
			++i;
		}
		return ret;
	}
}