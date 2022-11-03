import java.io.InputStream;
import java.io.OutputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class Task {

	private static final boolean readFromFile = false;
	private static final String fileInputName = "input.txt",
								fileOutputName = "output.txt";
	
	public static void main(String args[]){
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FileOutputStream fileOutputStream;
		FileInputStream fileInputStream;
		if (readFromFile){
			try{
				fileInputStream = new FileInputStream(new File(fileInputName));
				fileOutputStream = new FileOutputStream(new File(fileOutputName));
			}catch (FileNotFoundException e){
				throw new RuntimeException(e);
			}
		}
		PrintWriter out = new PrintWriter((readFromFile)?fileOutputStream:outputStream);
		InputReader in = new InputReader((readFromFile)?fileInputStream:inputStream);
		
		Solver s = new Solver(in,out);
		s.solve();
		
		out.close();
	}
}

class Solver{
	InputReader in;
	PrintWriter out;
	
	
	public void solve(){
		String
			ss1 = in.nextLine(),
			ss2 = in.nextLine(),
			ss3 = in.nextLine();
		ss1 = ss1.toLowerCase();
		ss2 = ss2.toLowerCase();
		ss3 = ss3.toLowerCase();
		StringBuilder s1 = new StringBuilder(ss1),
					  s2 = new StringBuilder(ss2),
					  s3 = new StringBuilder(ss3);
		int i=0;
		while (i<s1.length())
			if (s1.charAt(i)=='-' || s1.charAt(i)=='_' || s1.charAt(i)==';')
				s1.deleteCharAt(i);
			else
				i++;
		i=0;
		while (i<s2.length())
			if (s2.charAt(i)=='-' || s2.charAt(i)=='_' || s2.charAt(i)==';')
				s2.deleteCharAt(i);
			else
				i++;
		i=0;
		while (i<s3.length())
			if (s3.charAt(i)=='_' || s3.charAt(i)=='-' || s3.charAt(i)==';')
				s3.deleteCharAt(i);
			else
				i++;
		ss1 = new String(s1);
		ss2 = new String(s2);
		ss3 = new String(s3);
		String a[] = {ss1+ss2+ss3,
					  ss1+ss3+ss2,
					  ss2+ss1+ss3,
					  ss2+ss3+ss1,
					  ss3+ss1+ss2,
					  ss3+ss2+ss1};
		int n = in.nextInt();
		for (i=0;i<n;i++){
			String tmp = in.nextLine();
			tmp = tmp.toLowerCase();
			StringBuilder temp = new StringBuilder(tmp);
			int j =0;
			while (j<temp.length())
				if (temp.charAt(j)=='_' || temp.charAt(j)=='-' || temp.charAt(j)==';')
					temp.deleteCharAt(j);
				else
					j++;
			tmp = new String(temp);
			boolean found = false;
			for (j=0;j<6;j++)
				if (a[j].equals(tmp)){
					found = true;
					break;
				}
			out.println((found)?"ACC":"WA");
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