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
import java.util.StringTokenizer;

public class Task {

	private static final boolean readFromFile = false;
	
	public static void main(String args[]){
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FileOutputStream fileOutputStream;
		FileInputStream fileInputStream;
		if (readFromFile){
			try{
				fileInputStream = new FileInputStream(new File("input.txt"));
				fileOutputStream = new FileOutputStream(new File("output.txt"));
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
		int countOperation = in.nextInt(),
			sizeOfMemory = in.nextInt();
		int memory[] = new int[sizeOfMemory];
		boolean usedId[] = new boolean[10000];
		int tekId=0;
		Arrays.fill(memory,-1);
		
		for (int i=0;i<countOperation;i++){
			String nameOfOperation = in.next();
			if (nameOfOperation.equals("defragment")){
				for (int j=0;j<sizeOfMemory;j++)
					if (memory[j]==-1)
						for (int k=j+1;k<sizeOfMemory;k++)
							if (memory[k]!=-1){
								memory[j]=memory[k];
								memory[k]=-1;
								break;
							}
			}else
			if (nameOfOperation.equals("alloc")){
				int countBytes = in.nextInt();
				int found = -1;
				for (int j=0;j<sizeOfMemory-countBytes+1;j++){
					boolean free = true;
					for (int k=j;k<=j+countBytes-1;k++)
						if (memory[k]!=-1){
							free=false;
							break;
						}
					if (free){
						found = j;
						break;
					}
				}
				if (found==-1)
					out.println("NULL");
				else{
					int ans = ++tekId;
					usedId[ans]=true;
					for (int j=found;j<=found+countBytes-1;j++)
						memory[j]=ans;
					out.println(ans);
				}
			}else{
				int delId = in.nextInt();
				if (delId<=0 || delId>tekId || !usedId[delId])
					out.println("ILLEGAL_ERASE_ARGUMENT");
				else{
					usedId[delId]=false;
					for (int j=0;j<sizeOfMemory;j++)
						if (memory[j]==delId)
							memory[j]=-1;
				}
			}
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