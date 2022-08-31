import java.io.*;

public class Demo
{
	public static void main (String[] args) throws IOException
	{
		int n,t;
		InputStreamReader in=new InputStreamReader(System.in);
		BufferedReader br=new BufferedReader(in);
		n=Integer.parseInt(br.readLine());
		for(int i=1;i<n;i++){
  		int z=i*(i+1);
  		if(n<z)break;
  		t=(int)Math.sqrt(2*n-z);
  		t=t*(t+1);
  		if(t==2*n-z){
  			System.out.println("YES");
  			return;
  		}
  	}
  		System.out.println("NO");
	}
}