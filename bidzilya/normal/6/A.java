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

class Solver{
	InputReader in;
	PrintWriter out;
	
	private int checkTriangle(int a, int b, int c){
		if (a==b+c)
			return 1;
		else
		if (a<b+c)
			return 2;
		else
			return 0;
	}
	
	public void solve(){
		int a[] = new int[4];
		for (int i=0;i<4;i++)a[i]=in.nextInt();
		for (int i=0;i<3;i++)
			for (int j=i+1;j<4;j++)
				if (a[j]>a[i]){
					int buf=a[i];a[i]=a[j];a[j]=buf;
				}
		int ans=0;
		for (int i=0;i<4;i++)
			for (int j=i+1;j<4;j++)
				for (int k=j+1;k<4;k++)
					ans=Math.max(ans,checkTriangle(a[i],a[j],a[k]));
		switch (ans){
		case 0:out.println("IMPOSSIBLE");break;
		case 1:out.println("SEGMENT");break;
		case 2:out.println("TRIANGLE");break;
		}
	}

		
	Solver(InputReader in, PrintWriter out){
		this.in=in;
		this.out=out;
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