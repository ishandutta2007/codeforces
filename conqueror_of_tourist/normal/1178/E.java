import java.util.*;
public class Trial
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		int n = s.length();
		char[] out = new char[n/4];
	    for(int i = 0; i < n/4 ; i += 1){
	        char[] cs = {s.charAt(2*i),s.charAt(2*i+1),s.charAt(n-2*i-1),s.charAt(n-2*i-2)};
	        int[] count = new int[3];
	        for(char c : cs){
	            count[c-'a'] ++;
	        }
	        if (count[0] >= 2){
	            out[i] = 'a';
	        }
	        else if (count[1] >= 2){
	            out[i] = 'b';
	        }
	        else out[i] = 'c';
	    }
	    String outS = new String(out);
	    String outRev = new StringBuilder(outS).reverse().toString();
	    if (n % 4 == 0){
	        System.out.println(outS+outRev);
	    }
	    else{
	        String outMid = new String(new char[] {s.charAt(n/2)});
	        System.out.println(outS+outMid+outRev);	        
	    }
	}
}