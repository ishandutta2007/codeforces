import java.io.InputStream;
import java.io.OutputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
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
	private InputReader in;
	private PrintWriter out;
	Solver(InputReader in, PrintWriter out){
		this.in = in;
		this.out = out;
	}
	
	public void solve(){
		String s = in.next(),
				t = in.next();
		if (s.length()!=t.length()){
			out.println("NO");
			return;
		}
		int pos1=-1,pos2=-1,cnt=0;
		for (int i=0;i<s.length();i++)
			if (s.charAt(i)!=t.charAt(i)){
				cnt++;
				pos1=pos2;
				pos2=i;
			}
		if (cnt==1 || cnt>2){
			out.println("NO");
			return;
		}
		char s1=s.charAt(pos1),
				s2=s.charAt(pos2),
				t1=t.charAt(pos1),
				t2=t.charAt(pos2);
		if (s1!=t2 || s2!=t1)
			out.println("NO");
		else
			out.println("YES");
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