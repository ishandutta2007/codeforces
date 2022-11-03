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

public class Main{
    
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
    
    public void solve(){
    	long x = in.nextInt();
    	x = Math.abs(x);
    	long tek = 0,
    		step = 0;
    	while (tek<x || tek%2!=x%2){
    		step += 1;
    		tek += step;
    	}
    	out.println(step);
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
    
    public String nextLine(){
        try{
            return buf.readLine();
        }catch (IOException e){
            throw new RuntimeException(e);
        }
    }
}