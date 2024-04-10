using System;
namespace Application
{
    public class Solution
    {
        public static void Main(string[] args)
        {
            int l;
            int r;
            string s=Console.ReadLine();
            string[] tokens=s.Split();
            l=Convert.ToInt32(tokens[0]);
            r=Convert.ToInt32(tokens[1]);
            long base2=1;
            int ans=0;
            for (;base2<=r;base2*=2)
            {
                long base3=base2;
                for (;base3<=r;base3*=3)
                    if (base3>=l&&base3<=r)
                        ans+=1;
            }
            Console.WriteLine(ans);
        }
    }
}