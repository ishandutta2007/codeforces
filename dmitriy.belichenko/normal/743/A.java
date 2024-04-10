import java.io.*;
import java.util.*;
import java.math.*;

public class Main 
{
	

	public static void main(String[] args) throws Exception
	{

		int u = 0;
		// TODO Auto-generated method stub
//		 Scanner in = new Scanner(new File("search.in"));
//		    PrintWriter out = new PrintWriter(new File("search.out"));
//			// TODO Auto-generated method stub
		   PrintWriter out = new PrintWriter(System.out);
		   Scanner in = new Scanner(System.in);
		   //String a = in.nextLine();
		 int n = in.nextInt();
		 int a = in.nextInt();
		 int b = in.nextInt();
		String s = in.next();
		 a--; b--;
			
			
			if(s.charAt(a) == s.charAt(b))
				out.println(0);
			else out.println(1);
				out.close();
		}
	}