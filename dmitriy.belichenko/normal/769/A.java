/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author bossbelik
 */
import java.io.*;
import java.util.*;
import java.math.*;
import java.util.concurrent.ThreadLocalRandom;
public class Main 
{

		    
	public static void main(String[] args) throws Exception
	{
            
		
	      Scanner in = new Scanner(System.in);
              PrintWriter out = new PrintWriter(System.out);
        
      //   Scanner in = new Scanner(new File ("phi.in"));
      //   PrintWriter out = new PrintWriter(new File ("phi.out"));
         int n;
        n = in.nextInt();
        int a[] = new int[n];
        for(int i = 0; i < n; i++)
        {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);
        
         out.print(a[n/2]);
        out.close();
         }
 }