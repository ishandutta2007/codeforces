import java.util.*;

public class Sol{
	public static void main(String[] argc){
		Scanner sc = new Scanner(System.in);
		String s = sc.next().toLowerCase(), ans="";
		for (char c:s.toCharArray())
			if (c != 'a' && c != 'o' && c != 'y' && c != 'i' && c != 'e' && c != 'u'){
				ans += '.';
				ans += c;
			}
		System.out.println(ans);
	}
}