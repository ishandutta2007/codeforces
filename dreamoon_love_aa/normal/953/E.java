import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

public class Main{
    static int[] stk = new int[200000];
	public static void main(String[] argc){
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
		int t = in.nextInt();
        int sn=0;
		while (t-- > 0){
			int x = in.nextInt();
			while(x!=-1){
                if(sn == 0 || stk[sn-1] != x){
                    stk[sn]=x;
                    sn++;
                    x=-1;
                }
                else{
                    sn--;
                    x++;
                }
            }
		}
        System.out.println(sn);
        int i=0;
        for(i=0;i< sn; i++){
            out.print(stk[i]);
            if(i+1<sn){
                out.print(' ');
            }
        }
        out.println("");
        out.close();
	}
    

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
    }
}