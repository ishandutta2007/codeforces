//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
string wz,s,in[105];
int out[105];
int k,cnt;
map<string,int> m;
int main(){
    ios::sync_with_stdio(0);
    getline(cin,s);
    string t=" begin{thebibliography}{99}";
    t[0]=92;
    while(s!=t)wz+=s,getline(cin,s);
    getline(cin,s);
    t=" end{thebibliography}";
    t[0]=92;
    while(s!=t)in[++k]=s,getline(cin,s);
    for(int i=1;i<=k;++i){
        string q="";
        int l=0;
        while(in[i][l]!='{')++l;
        ++l;
        while(in[i][l]!='}')q+=in[i][l],++l;
        m[q]=i;
    }
    bool ok=0;
    for(int i=0;i<wz.size();++i){
        if(wz[i]=='{')ok=1,s="";
        else if(wz[i]=='}')ok=0,out[++cnt]=m[s];
        else if(ok)s+=wz[i];
    }
    ok=1;
    for(int i=1;i<=k;++i)if(out[i]!=i)ok=0;
    if(ok){
        cout<<"Correct"<<endl;
    }
    else{
        cout<<"Incorrect"<<endl;
        t=" begin{thebibliography}{99}";
        t[0]=92;
        cout<<t<<endl;
        for(int i=1;i<=k;++i)cout<<in[out[i]]<<endl;
        t=" end{thebibliography}";
        t[0]=92;
        cout<<t<<endl;
    }
	//system("pause");
	return 0;
}