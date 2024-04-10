import java.io.PrintWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.Random;
import java.util.StringTokenizer;

public class Task{
	
	static final boolean readFromFile = false;
	static final String fileInputName = "input.txt",
						fileOutputName = "output.txt";
	
	public static void main(String args[]){
		FileInputStream fileInputStream;
		FileOutputStream fileOutputStream;
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		if (readFromFile){
			try{
				fileInputStream = new FileInputStream(new File(fileInputName));
				fileOutputStream = new FileOutputStream(new File(fileOutputName));
			}catch (FileNotFoundException e){
				throw new RuntimeException(e);
			}
		}
		PrintWriter out = new PrintWriter((readFromFile)?fileOutputStream:outputStream);
		InputReader in  = new InputReader((readFromFile)?fileInputStream:inputStream);
		
		Solver s = new Solver(in, out);
		s.solve();
		
		out.close();
	}
}

class Solver{
	private PrintWriter out;
	private InputReader in;
	
	int posCon,
		posAni,
		n,
		dx;
	
	public void solve(){
		n = in.nextInt();
		posAni = in.nextInt();
		posCon = in.nextInt();
		String s = in.nextLine();
		if (s.equals("to head"))
			dx = -1;
		else
			dx = 1;
		if (dx==1 && posCon==n ||
			dx==-1 && posCon==1)
			dx *= -1;
		s = in.nextLine();
		for (int i=0;i<s.length();i++)
			if (s.charAt(i)=='1'){
				posCon += dx;
				if (posCon==1 || posCon==n)
					dx *= -1;
				if (posCon==1)
					posAni = n;
				else
				if (posCon==n)
					posAni = 1;
				else
				if (dx==1)
					posAni=1;
				else
					posAni=n;
			}else{
				if (posAni+dx<=n && posAni+dx>=1 &&
					(dx==1 && posCon<posAni ||
					dx==-1 && posCon>posAni))
						posAni += dx;
				posCon += dx;
				if (posCon==1 || posCon==n)
					dx *= -1;
				if (posCon == posAni){
					out.println("Controller" + " " + (i+1));
					return;
				}
			}
		out.println("Stowaway");
	}
	
	Solver(InputReader in, PrintWriter out){
		this.in = in;
		this.out = out;
	}
}

class InputReader{
	StringTokenizer tok;
	BufferedReader buf;
	
	InputReader(InputStream in){
		tok = null;
		buf = new BufferedReader(new InputStreamReader(in));
	}

	InputReader(FileInputStream in){
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
	public String nextLine(){
		try{
			return buf.readLine();
		}catch (IOException e){
			return null;
		}
	}
}