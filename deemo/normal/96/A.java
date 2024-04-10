import java.util.*;

public class Sol{
	public static void main(String[] argc){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		System.out.println(s.contains("1111111") || s.contains("0000000")?"YES":"NO");
	}
}