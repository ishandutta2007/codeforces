#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long tmp;
    cin>>tmp;
    for(int i=2;i<=n;i++)
    {
        int tmp1;
        cin>>tmp1;
        cout<<tmp1+tmp<<" ";
        tmp=tmp1;
    }
    cout<<tmp<<endl;
}