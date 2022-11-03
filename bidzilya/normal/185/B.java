import java.io.InputStream;
import java.io.OutputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.StringTokenizer;

public class Task {

	public static void main(String args[]){
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		PrintWriter out = new PrintWriter(outputStream);
		InputReader in = new InputReader(inputStream);
		
		Solver s = new Solver(in,out);
		s.solve();
		
		out.close();
	}
}

class Coord{
	public double x,y,z;
	Coord(double x,double y,double z){
		this.x = x;
		this.y = y;
		this.z = z;
	}
	
	public void print(PrintWriter out){
		out.println(x + " " + y + " " + z);
	}
}

class Solver{
	private InputReader in;
	private PrintWriter out;
	Solver(InputReader in, PrintWriter out){
		this.in = in;
		this.out = out;
	}
	
	private double s,a,b,c;
	
	private double f(double x, double y, double z){
		double lx,ly,lz;
		lx = (x==0)?-1e40:Math.log(x);
		ly = (y==0)?-1e40:Math.log(y);
		lz = (z==0)?-1e40:Math.log(z);
		return a*lx + b*ly + c*lz;
	}
	
	private double Ternary2(double x){
		double yl=0,yr=s-x;
		for (int iter=0;iter<=222;iter++){
			double m1 = (2*yl+yr)/3,
				   m2 = (yl+2*yr)/3,
				   z1 = s-x-m1,
				   z2 = s-x-m2,
				   f1 = f(x,m1,z1),
				   f2 = f(x,m2,z2);
			if (f2>f1)
				yl = m1;
			else
				yr = m2;
		}
		return yl;
	}
	
	private Coord Ternary(){
		double xl=0,xr=s;
		for (int iter=0;iter<=222;iter++){
			double m1 = (2*xl+xr)/3,
				   m2 = (2*xr+xl)/3,
				   y1 = Ternary2(m1),
				   y2 = Ternary2(m2),
				   z1 = s-m1-y1,
				   z2 = s-m2-y2,
			       f1 = f(m1,y1,z1),
				   f2 = f(m2,y2,z2);	
			if (f2>f1)
				xl=m1;
			else
				xr=m2;
		}
		double y = Ternary2(xl),
			   z = s-xl-y;	
		return new Coord(xl,y,z);
	}
	
	public void solve(){
		s=in.nextDouble();
		a=in.nextDouble();
		b=in.nextDouble();
		c=in.nextDouble();
		
		Coord ans = Ternary();
		ans.print(out);
	}
}

class InputReader{
	private BufferedReader buf;
	private StringTokenizer tok;
	
	InputReader(InputStream in){
		tok = null;
		buf = new BufferedReader(new InputStreamReader(in));
	}
	
	public String next(){
		while (tok==null || !tok.hasMoreTokens()){
			try{
				tok = new StringTokenizer(buf.readLine());
			}catch (IOException e){
				throw new RuntimeException(e);
			}
		}
		return tok.nextToken();
	}
	
	public int nextInt(){
		return Integer.parseInt(next());
	}
	
	public long nextLong(){
		return Long.parseLong(next());
	}
	
	public double nextDouble(){
		return Double.parseDouble(next());
	}
	
	public float nextFloat(){
		return Float.parseFloat(next());
	}
}