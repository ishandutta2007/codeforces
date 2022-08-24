import java.util.ArrayList;
import java.util.HashSet;
import java.io.*;
import java.util.*;
import java.lang.String;
import java.util.Random;
public class sas {
	public static ArrayList<Integer> data;
	public static ArrayList<Integer> days;
	public static boolean search(int n){
		HashMap<Integer, Integer> help = new HashMap<Integer, Integer>();
		for (int i=0;i<n;i++){
			if (data.get(i) > 0){
				help.put(data.get(i), i +1);
			}
		}
		if (help.size() < days.size()){
			return false;
		}
		else{
			HashMap<Integer, Integer> h = new HashMap<Integer, Integer>();
			ArrayList<Integer> h1 = new ArrayList<Integer>();
			for (int key : help.keySet()){
				h.put(help.get(key), key);
				h1.add(help.get(key));
			}
			Collections.sort(h1);
			int ukaz = 0;
			for (int element:h1){
				int d = days.get(h.get(element) - 1);
				if (ukaz + d >= element){
					return false;
				}
				else{
					ukaz += d + 1;
				}
			}
		}
		return true;
	}
    public static void main(String []args) throws IOException{
    	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String [] tokens = reader.readLine().split(" ");
        data = new ArrayList<Integer>();
        days = new ArrayList<Integer>();
        int n = Integer.parseInt(tokens[0]);
        int m = Integer.parseInt(tokens[1]);
        tokens = reader.readLine().split(" ");
        for (int i=0; i<n;i++){
        	data.add(Integer.parseInt(tokens[i]));
        }
        tokens = reader.readLine().split(" ");
        for (int i=0; i<m;i++){
        	days.add(Integer.parseInt(tokens[i]));
        }
        int left = 0;
        int right = n + 1;
        while (right - left > 1){
        	int mid = (right + left) / 2;
        	boolean answer = search(mid);
        	if (answer == true){
        		right = mid;
        	}
        	else{
        		left = mid;
        	}
        }
        if (right > n){
        	System.out.println(-1);
        }
        else{
        	System.out.println(right);
        }
        }
    }