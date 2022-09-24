import java.util.*;
import java.io.*;
import java.math.*;
public class Main {

	/**
	 * @param args
	 */

	static int n;
	static double x[] = new double[60005];
	static double v[] = new double[60005];
	static double f(double xa , int n)
	{
		double p = 0;
		for (int i = 0; i < n; i++)
		{
			double u = xa - x[i];
			double o = u / v[i];
			p = Math.max(p, Math.abs(o));
		}
		return p;
	}

	public static void main(String[] args)throws Exception 
	{
		
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("subseq.in"));
	//	PrintWriter out = new PrintWriter(new File("subseq.out"));
		PrintWriter out = new PrintWriter(System.out);
		

		int n = in.nextInt();

		
		
			for (int i = 0; i < n; i++)  x[i] = in.nextDouble();
			for (int i = 0; i < n; i++) v[i] = in.nextDouble();
			double l = 0, r = 1e9+1, EPS = 0.000001; 
			while (r - l > EPS) {
				double m1 = l + (r - l) / 3,
					m2 = r - (r - l) / 3;
				if (f(m1,n) > f(m2,n))
					l = m1;
				else
					r = m2;
			}
			out.println(String.format("%(.6f ", f(l,n)));
	 out.close();
	

 }
}