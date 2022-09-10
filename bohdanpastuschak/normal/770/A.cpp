#include <iostream>

using namespace std;

char a[26]={'q','a','z','w','s','x','e','d','c','r','f','v','t','g','b','y','h','n','u','j','m','i','k','o','l','p'};

int main()
{
          int n,k;
          cin>>n>>k;
          for(int i=0;i<n;i++)
                    cout<<a[i%k];
}