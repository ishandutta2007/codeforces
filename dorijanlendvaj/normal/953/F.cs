using System;
using System.Linq;
class Program
{
    static void Main()
    {
        var b = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        long n = b[0], p = b[1], m = b[2];
        long pdan=0, money=0, res=0; 
        for (var i = 0; i < n; ++i)
        { 
            var a = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
            long d = a[0], mn = a[1];
            if (d<=m+1)
            {
                long nov=(money+p)/p,ddiff=d-pdan;
                nov=ddiff-nov;
                if (nov>ddiff) nov=ddiff;
                if (nov<0) nov=0;
                res+=nov;
                money+=mn-ddiff*p;
            }
            else if (d>m+1 && pdan<=m+1)
            {
                long nov=(money+p)/p,ddiff=m+2-pdan;
                nov=ddiff-nov;
                if (nov>ddiff) nov=ddiff;
                if (nov<0) nov=0;
                res+=nov;
                money+=mn-ddiff*p;
            }
            pdan=d;
        }
        if (pdan<=m)
        {
            long nov=(money+p)/p,ddiff=m+1-pdan;
            nov=ddiff-nov;
            if (nov>ddiff) nov=ddiff;
            if (nov<0) nov=0;
            res+=nov;
        }
        Console.WriteLine(res);
    }

}