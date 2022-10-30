using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Swap<T>(ref T a, ref T b)
        {
            T t = a;
            a = b;
            b = t;
        }
        static void Main(string[] args)
        {
            int T = Convert.ToInt32(Console.ReadLine());
            for (int Case = 0; Case < T; Case++)
            {
                String[] input = Console.ReadLine().Split(' ');
                int n = Convert.ToInt32(input[0]);
                int m = Convert.ToInt32(input[1]);
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (i == j && i == 0)
                        {
                            Console.Write('W');
                        }
                        else
                        {
                            Console.Write('B');
                        }
                    }
                    Console.WriteLine();
                }
            }
        }
    }
}