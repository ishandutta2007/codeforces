import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int ar[]=new int[n];
		int arr[]=new int[n];
	for(int i=0;i<n;i++)
	{
		ar[i]=sc.nextInt();
	}
	for(int i=0;i<n;i++)
	{
		int ra[]=new int[n];
		if(arr[i]==0)
		arr[i]=abso(ar,arr,ra,i);
	}
	for(int i=0;i<n;i++)
	{
		System.out.println(arr[i]+" ");
	}}

static int abso(int ar[],int arr[],int ra[],int i)
{
	
		ra[i]++;
		if(ra[i]==2)
		{
			return i+1;
		}
		int k=abso(ar,arr,ra,ar[i]-1);
		return k;
	
}



}