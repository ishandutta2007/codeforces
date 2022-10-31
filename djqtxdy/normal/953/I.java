import java.util.*;
import java.util.Arrays;
public class Sol{
	public static void main(String[] argc){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int tt=t;
		int[] ds;
		ds= new int[t];
		int cnt = 0;
		while (t-- > 0){
			String s = sc.next();
			int v1 = s.charAt(0)-48;
			int v2 = s.charAt(1)-48;
			int v3 = s.charAt(3)-48;
			int v4 = s.charAt(4)-48;
			int hh = v1*10+v2;
			int mm = v3*10+v4;
			ds[cnt] = hh*60+mm;
			cnt++;
		}
		Arrays.sort(ds);
		int Mx = 0;
		for (int i=1;i<=tt-1;i++){
		    if (Mx< ds[i]-ds[i-1]-1){
		        Mx= ds[i]-ds[i-1]-1;
		    }
		}
	    if (ds[0]+1440-ds[tt-1]-1>Mx){
	        Mx=ds[0]+1440-ds[tt-1]-1;
	    }
	    if (Mx/60<10){
	        System.out.printf("0");
	    }
		System.out.printf("%d:",Mx/60);
		if (Mx%60<10){
	        System.out.printf("0");
	    }
	    System.out.printf("%d",Mx%60);
	}
}