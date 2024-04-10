import java.io.*;
import java.util.*;
import java.math.*;

public class Main 
{
	
	public static void main(String[] args) throws Exception
	{

		

		   PrintWriter out = new PrintWriter(System.out);
		   Scanner in = new Scanner(System.in);
		 
		
		 
		String s = in.nextLine();
		if (s.charAt(s.length() - 1) == 'k' && (s.charAt(0) == '6' || s.charAt(0) == '5' )  && s.charAt(1) == ' ')
		{
			System.out.println( "53" );
			return ;
		}
		//cout << s[s.size() - 1];
		if (s.charAt(s.length() - 1) == 'k')System.out.println( "52" );
		else
		{ 
			if(s.charAt(0) == '3' && s.charAt(1) == '0') System.out.println( "11" );
			else if(s.charAt(0) == '3' && s.charAt(1) == '1') System.out.println( "7" );
			else  System.out.println( "12" );
		}
	}
	
}