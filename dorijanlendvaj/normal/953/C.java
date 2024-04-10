import java.util.*;
public class project{
    public static void main(String[]args){
	Scanner s = new Scanner(System.in);
	int n=s.nextInt(),le=0,le1=1,pro=s.nextInt();
	String sol="YES";
	n--;
	while (n-- > 0)
	{
	    int o=s.nextInt();
	    if (o==pro)
	    {
	        ++le1;
	    }
	    else
	    {
	        if (le==0) le=le1;
	        if (le!=le1) sol="NO";
	        le1=1;
	        pro=o;
	    }
	}
	if (le==0) le=le1;
	if (le!=le1) sol="NO";
	System.out.println(sol);
}
}