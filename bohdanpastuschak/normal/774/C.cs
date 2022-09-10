using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CS_Project1
{
    class Program
    {

        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            string ans="";
        
            if (n % 2 == 0)
            {
                for (int i = 0; i < n / 2; ++i)
                    ans += "1";
            }
            else
            {
                ans += "7";
                for (int i = 1; i < n / 2; ++i)
                    ans += "1";
            }
            Console.Write(ans);
        }
    }
}