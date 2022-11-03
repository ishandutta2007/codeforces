import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.util.StringTokenizer;

public class MyTask{
	
	public static void main(String args[]){
		OutputStream outputstream = System.out;
		InputStream inputstream = System.in;
		PrintWriter out = new PrintWriter(outputstream);
		InputReader in = new InputReader(inputstream); 
		
		Solver s = new Solver(in, out);
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
		int n = in.nextInt(),
			m = in.nextInt();
		for (int i=0;i<n;i++){
			int s = in.nextInt(),
				f = in.nextInt(),
				t = in.nextInt();
	
			if (s==f)
				out.println(t);
			else{
				int cnt = (int)t/(m-1),
					pos = t%(m-1)+1;
				boolean up = true;
				if (cnt%2==1){
					pos = m - pos+1;
					up = false;
				}
				if (s<f){
					if (!up){
						out.println(t+pos-2+f);
					}else{
						if (pos<=s)
							out.println(t+f-pos);
						else
							out.println(t+2*m-2-pos+f);
					}
				}else{
					if (!up){
						if (pos>=s)
							out.println(t+pos-f);
						else
							out.println(t+pos-2+2*m-f);
					}else{
						out.println(t+2*m-pos-f);
					}
				}
			}
		}
	}
}

class InputReader{
	private BufferedReader buf;
	private StringTokenizer tok;
	
	InputReader(InputStream in){
		buf = new BufferedReader(new InputStreamReader(in));
		tok = null;
	}
	
	public String next(){
		while (tok==null || !tok.hasMoreTokens())
			tok = new StringTokenizer(nextLine());
		return tok.nextToken();
	}
	
	public int nextInt(){
		return Integer.parseInt(next());
	}
	
	public long nextLong(){
		return Long.parseLong(next());
	}
	
	public String nextLine(){
		try{
			return buf.readLine();
		}catch (IOException e){
			throw new RuntimeException();
		}
	}
	
	public Double nextDouble(){
		return Double.parseDouble(next());
	}
	
	public Float nextFloat(){
		return Float.parseFloat(next());
	}
}