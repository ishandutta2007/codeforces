#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cnt[26];

void print(int x)
{
    cout << (char)(x+'a');
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        for(int i=0;i<26;i++) cnt[i] = 0;
        string s; cin >> s;
        int n = s.size(), C = 0;
        for(int i=0;i<n;i++)
        {
            cnt[s[i] - 'a']++;
            if(cnt[s[i] - 'a'] == 1) C++;
        }

        if(C == 1)
        {
            cout << s << "\n";
            continue;
        }

        bool flag = false;
        for(int i=0;i<26;i++)
        {
            if(cnt[i] == 1)
            {
                print(i);
                for(int j=0;j<26;j++)
                {
                    if(j == i) continue;
                    for(int k=0;k<cnt[j];k++) print(j);
                }
                cout << "\n";
                flag = true;
                break;
            }
        }
        if(flag) continue;

        if(C == 2)
        {
            int a, b;
            for(int i=0;i<26;i++)
                if(cnt[i]) {a = i; break;}
            for(int i=a+1;i<26;i++)
                if(cnt[i]) {b = i; break;}

            int A = cnt[a], B = cnt[b];

            if(A <= B+2)
            {
                print(a);
                print(a);
                A -= 2;
                if(A == 0) B--;
                print(b);
                B--;
                for(int i=1;i<A;i++)
                {
                    print(a);
                    print(b);
                }
                if(A > 0) { print(a); }
                for(int i=1;i<=B-A+1;i++)
                {
                    print(b);
                }
                cout << "\n";
            }
            else
            {
                print(a); A--;
                for(int i=1;i<=B;i++) print(b);
                for(int i=1;i<=A;i++) print(a);
                cout << "\n";
            }

            continue;
        }

        int a;
        for(int i=0;i<26;i++)
        {
            if(cnt[i]) {a = i; break;}
        }
        int A = cnt[a];

        if(A <= (n+2)/2)
        {
            print(a);
            A--;
            while(A > 0)
            {
                print(a);
                for(int i=a+1;i<26;i++)
                {
                    if(cnt[i])
                    {
                        cnt[i]--;
                        print(i);
                        break;
                    }
                }
                A--;
            }
            for(int i=a+1;i<26;i++)
            {
                for(int j=1;j<=cnt[i];j++) print(i);
            }
            cout << "\n";
        }
        else
        {
            print(a); A--;
            int b;
            for(int i=a+1;i<26;i++)
            {
                if(cnt[i]) { b = i; break; }
            }
            int c;
            for(int i=b+1;i<26;i++)
            {
                if(cnt[i]) {c = i; break; }
            }

            print(b); cnt[b]--;
            for(int i=1;i<=A;i++) print(a);
            print(c); cnt[c]--;

            for(int i=a+1;i<26;i++)
            {
                for(int j=1;j<=cnt[i];j++) print(i);
            }

            cout << "\n";
        }
    }
}