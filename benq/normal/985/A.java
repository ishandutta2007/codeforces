import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] v = new int[n/2];
        for (int i = 0; i < v.length; ++i)
            v[i] = in.nextInt();
        Arrays.sort(v);
    
        int s0 = 0;
        for (int i = 0; i < v.length; ++i) 
        	s0 += Math.abs(v[i]-2*i-1);
        int s1 = 0;
        for (int i = 0; i < v.length; ++i) 
        	s1 += Math.abs(v[i]-2*i-2);
        
        System.out.print(Math.min(s1,s0));
    }
}