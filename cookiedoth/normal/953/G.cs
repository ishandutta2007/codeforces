using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{

    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var x = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        
        int even = 0, odd = 0;
        for (int i = 0; i < n; ++i) {
            if (x[i] % 2 == 0)
                even++;
            else
                odd++;
        }
        
        int ans = Math.Min(even, odd);
        
        even -= ans;
        odd -= ans; 
        
        if (odd > 0)
            ans += (odd / 3);
        
        Console.WriteLine(ans);
    }

}