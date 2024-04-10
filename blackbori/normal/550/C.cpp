#include <bits/stdc++.h>

using namespace std;

string s;

bool TRUE(int a,int b,int c)
{
    if(((s[a]-'0')*100+(s[b]-'0')*10+(s[c]-'0'))%8!=0) return false;
    printf("YES\n");
    printf("%c%c%c\n",s[a],s[b],s[c]);

    return true;
}

bool TRUE2(int a,int b)
{
    if(((s[a]-'0')*10+(s[b]-'0'))%8!=0) return false;
    printf("YES\n");
    printf("%c%c\n",s[a],s[b]);

    return true;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> s;

    bool f;
    int i1,i2,i3;

    for(i1=0; i1<s.size(); i1++){
        if(s[i1]=='0' || s[i1]=='8'){
            printf("YES\n");
            printf("%c\n",s[i1]);
            return 0;
        }
    }

    for(i1=0; i1<s.size(); i1++){
        for(i2=i1+1; i2<s.size(); i2++){
            f=TRUE2(i1,i2);
            if(f) return 0;
        }
    }

    for(i1=0; i1<s.size(); i1++){
        for(i2=i1+1; i2<s.size(); i2++){
            for(i3=i2+1; i3<s.size(); i3++){
                f=TRUE(i1,i2,i3);
                if(f) return 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}