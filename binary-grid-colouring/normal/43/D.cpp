#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]) {

   int n,m;
   std::cin >> n >> m;
   if(n==1 && m==2) {
     std::cout << "0" << '\n';
     std::cout << "1 1" << '\n';
     std::cout << "1 2" << '\n';
     std::cout << "1 1" << '\n';
     return 0;
   }
   if(n==2 && m==1) {
     std::cout << "0" << '\n';
     std::cout << "1 1" << '\n';
     std::cout << "2 1" << '\n';
     std::cout << "1 1" << '\n';
     return 0;
   }
   //one of n and m is an even integer
   if((n * m % 2 == 0 && n != 1 && m != 1)) {
     std::cout << 0 << '\n';
     std::cout << "1 1" << '\n';
     // n is even
     if(n % 2 == 0)
     {
       for(int i=0;i<n;i++)
       {
         if(i % 2 == 0)
         {
           for(int j=0;j<m-1;j++)
           {
             std::cout << i+1 << " " << j+2 << '\n';
           }
         }

         if(i % 2 == 1)
         {
           for(int j=0;j<m-1;j++)
           {
             std::cout << i+1 << " " << m-j << '\n';
           }
         }
       }
       for(int i=0;i<n;i++)
       {
         std::cout << n-i << " " << 1 << '\n';
       }
     }
     // m is even
     else
     {
       for(int i=0;i<m;i++)
       {
         if(i % 2 == 0)
         {
           for(int j=0;j<n-1;j++) {
             std::cout << j+2 << " " << i+1 << '\n';
           }
         }
         if(i % 2 == 1)
         {
           for(int j=0;j<n-1;j++)
           {
             std::cout << n-j << " " << i+1 << '\n';
           }
         }
       }
       for(int i=0;i<m;i++) {
         std::cout << 1 << " " << m - i  << '\n';
       }
     }
   }

   else // Both n and m are odd integers
   {
     std::cout << "1" << '\n';
     std::cout << n << " " << m << " ";
     std::cout << "1 1" << '\n';
     for(int i=0;i<n;i++)
     {
       if(i % 2 == 0)
       {
         for(int j=0;j<m;j++)
         {
           std::cout << i+1 <<" " << j+1 << '\n';
         }
       }
       if(i % 2 == 1)
       {
         for(int j=0;j<m;j++)
         {
           std::cout << i+1 << " " << m-j << '\n';
         }
       }
     }
     std::cout << "1 1" << '\n';
   }
   return 0;
}