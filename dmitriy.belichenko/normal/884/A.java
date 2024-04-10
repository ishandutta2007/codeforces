import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class q1 {
    
    static class Scan {

        private final InputStream inputStream;
	private final byte[] buffer = new byte[1024];
	private int currentChar;
	private int numChars;
	private SpaceCharFilter filter;

	public Scan () {
            inputStream = System.in;
	}

	public int read () {
            if (numChars==-1)
		throw new InputMismatchException();

            if (currentChar >= numChars) {
		currentChar = 0;
		try {
                    numChars = inputStream.read(buffer);
		}
		catch (IOException e) {
                    throw new InputMismatchException();
		}
				
		if (numChars <= 0)				
                    return -1;
            }
            return buffer[currentChar++];
	}
	 
	public String nextLine () {
            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
            String str = "";
            
            try {
                str = br.readLine();
            }
            catch (IOException e) {
            }
            return str;
	}
	
        public int nextInt () {	
            int ch = read();
			
            while (isSpaceChar(ch)) 
		ch = read();
			
            int sgn = 1;
			
            if (ch == '-') {
		sgn = -1;
                ch = read();
            }
			
            int res = 0;
            do {
		if (ch < '0' || ch > '9') 
                    throw new InputMismatchException();
		res *= 10;
		res += ch - '0';
		ch = read();
            }
            while (!isSpaceChar(ch)); 
			
            return res * sgn;
	}
		
	public long nextLong () {
            int ch = read();
            
            while (isSpaceChar(ch))
		ch = read();
            
            int sgn = 1;
            
            if (ch == '-') {
		sgn = -1;
		ch = read();
            }
            
            long res = 0;
			
            do {
                if (ch < '0' || ch > '9')
                    throw new InputMismatchException();
		res *= 10;
		res += ch - '0';
		ch = read();
            }
            while (!isSpaceChar(ch));
            
            return res * sgn;
	}
		
	public double nextDouble () {
            int ch = read();
		
            while (isSpaceChar(ch))
		ch = read();
            
            int sgn = 1;
            if (ch == '-') {
		sgn = -1;
		ch = read();
            }
	
            double res = 0;
            while (!isSpaceChar(ch) && ch != '.') {
		if (ch == 'e' || ch == 'E')
                    return res * Math.pow(10, nextInt());
		if (ch < '0' || ch > '9')
                    throw new InputMismatchException();
		res *= 10;
		res += ch - '0';
		ch = read();
            }
            if (ch == '.') {
		ch = read();
		double m = 1;
		while (!isSpaceChar(ch)) {
                    if (ch == 'e' || ch == 'E')
			return res * Math.pow(10, nextInt());
                    if (ch < '0' || ch > '9')
                    	throw new InputMismatchException();
                    m /= 10;
                    res += (ch - '0') * m;
                    ch = read();
		}
            }
	
            return res * sgn;
	}
		
	public String readString () {
            int ch = read();
            while (isSpaceChar(ch))
		ch = read();
	
            StringBuilder res = new StringBuilder();
	
            do {
		res.appendCodePoint(ch);
		ch = read();
            } 
            while (!isSpaceChar(ch));
			
            return res.toString();
	}
	 
	public boolean isSpaceChar (int ch) {
            if (filter != null)
		return filter.isSpaceChar(ch);
            return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t' || ch == -1;
	}
	 
	public String next () {
            return readString();
	}

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
	}
    }
    
    static class Print {
        private final BufferedWriter bw;
        
        public Print () {
            this.bw=new BufferedWriter(new OutputStreamWriter(System.out));
        }
        
        public void print (Object object)throws IOException {
            bw.append(""+object);
        }
        
        public void println (Object object)throws IOException {
            print(object);
            bw.append("\n");
        }
        
        public void close () throws IOException {
            bw.close();
        }
    }
    
    private static void readArray (int[] arr, Scan scan) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scan.nextInt();
        }
    }
    
    private static void read2DArray (int[][] arr, Scan scan) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                arr[i][j] = scan.nextInt();
            }
        }
    }
    
    private static void printArray (int[] arr, char ch, Print pr) throws IOException {
        for (int i = 0; i < arr.length; i++) {
            pr.print(arr[i] + "" + ch);
        }
    }
    
    private static void print2DArray (int[][] arr, Print pr) throws IOException {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                pr.print(arr[i][j] + " ");
            }
            pr.println("");
        }
    }
    
    private static void sort2DArray (int[][] arr) {
        
        Arrays.sort (arr, new Comparator<int[]>() {
            public int compare (int[] a, int[] b) {
                return Integer.compare(a[0], b[0]);
            }
            
            /*public int compare (int[] a, int[] b) {
                if(a[0] < b[0]) 
                    return -1;
                else if(a[0] > b[0]) 
                    return 1;
                else
                    return Integer.compare(a[1], b[1]);
            }*/
        });
    }
    
    public static void main (String[] args) throws IOException {
        Scan sc = new Scan();
        Print pr = new Print();
        
        int n, t, i;
        n=sc.nextInt();
        t=sc.nextInt();
        
        int arr[] = new int[n];
        
        readArray(arr, sc);
        
        i=0;
        while(t>0) {
            t-=(86400-arr[i]);
            i++;
        }
        
        pr.println(i);
        
        pr.close();
    }
    
}