import java.util.*;
import java.io.*; 
import java.util.*;
import java.io.*; 
public class MM {
	static Scanner scanner=new Scanner(System.in);
	public static void main(String[] args) {
		int n=scanner.nextInt();
		int k=scanner.nextInt();
		int t=0;
		while(n-k*(t)>=t) {
			int z=n-k*(t);//z
			int s=0;
			while(z>0) {
				if(z%2==1)s++;
				z/=2;
			}
			if(s<=t) {
				System.out.println(t);
				return;
			}
			t++;
		}
		System.out.println(-1);
	}
}