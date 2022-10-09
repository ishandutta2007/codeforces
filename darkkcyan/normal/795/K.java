import java.util.*;
import java.io.*;

public class Sol{
    static boolean isVowel(char c) {
        return c == 'a' || c == 'e' ||c == 'i' || c == 'o' || c == 'u' || c == 'y';
    }
	public static void main(String[] argc) { try {
	    BufferedReader br = new BufferedReader(
                              new InputStreamReader(System.in));
 
		int n = Integer.parseInt(br.readLine());
		String s = br.readLine();
		StringBuilder ans = new StringBuilder();
		StringBuilder t = new StringBuilder("" + s.charAt(0));
		s += " ";
		for (int i = 1; i <= n; ++i) {
		    if (s.charAt(i) != s.charAt(i - 1)) {
		        char c = t.charAt(0);
		        if (!isVowel(c)) ans.append(t);
		        else if (c != 'o' && c != 'e') ans.append(c);
		        else if (t.length() == 2) ans.append(t);
		        else ans.append(c);
		        t.setLength(0);
		    }
		    t.append(s.charAt(i));
		}
		PrintWriter p = new PrintWriter(System.out);
		p.print(ans);
		p.close();
	} catch (Exception e) {} }
}