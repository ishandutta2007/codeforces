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
    long c;
    cin>>n>>c;
    long cnt=0;
    long last=0;
    for(int i=1;i<=n;i++)
    {
        long tmp;
        cin>>tmp;
        if(tmp-last>c) cnt=1;
        else cnt++;
        last = tmp;
    }
    cout<<cnt<<endl;
}