#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

const int MAX = 55;

int poc[55], kraj[55], k, treba, l1, l2;

ll a[55], b[55], spojab[55], spojba[55], spojaa[55], spojbb[55];
string s1, s2;
char s[4] = "ACB";

int Moze(int ACa, int ACb, int POCa, int POCb, int KRAJa, int KRAJb)
{
    int l, i;
    ll z=0;

    if (l1 < 2 && POCa != KRAJa || l2 < 2 && POCb != KRAJb)
        return 0;

    if (POCa == 1 && !KRAJa)
        z += spojaa[k-1];
    if (POCb == 1 && !KRAJb)
        z += spojbb[k-1];
    if (POCa == 1 && !KRAJb)
        z += spojba[k-1];
    if (POCb == 1 && !KRAJa)
        z += spojab[k-1];

    z += ACa * a[k-1];
    z += ACb * b[k-1];

    if (z != treba)
        return 0;

    l = l1;
    if (POCa != 0)
        l--;
    if (KRAJa != 1)
        l--;
    if (l/2 < ACa)
        return 0;

    l = l2;
    if (POCb != 0)
        l--;
    if (KRAJb != 1)
        l--;
    if (l/2 < ACb)
        return 0;

    s1 = s2 = "";

    s1 += s[POCa];

    for (i=1; i<l1-1; i++) {
        if (!ACa)
            s1 += "B";
        else {
            if (s1[i-1] == 'A') {
                s1 += "C";
                ACa--;
            }
            else
                s1 += "A";
        }
    }

    if (l1 > 1)
        s1 += s[KRAJa];



    s2 += s[POCb];

    for (i=1; i<l2-1; i++) {
        if (!ACb)
            s2 += "B";
        else {
            if (s2[i-1] == 'A') {
                s2 += "C";
                ACb--;
            }
            else
                s2 += "A";
        }
    }

    if (l2 > 1)
        s2 += s[KRAJb];

    return 1;
}

int main()
{
    int i, ACa, ACb, POCa, POCb, KRAJa, KRAJb, da=0;

    a[0] = 1;
    b[1] = 1;
    poc[1] = kraj[1] = 1;

    scanf("%d%d%d%d", &k, &treba, &l1, &l2);

    for (i=2; i<k; i++) {
        poc[i] = poc[i-2];
        kraj[i] = kraj[i-1];
        spojab[i] = spojab[i-2] + spojab[i-1];
        if (kraj[i-2] == 0 && poc[i-1] == 1)
            spojab[i]++;
        spojba[i] = spojba[i-2] + spojba[i-1];
        if (kraj[i-2] == 1 && poc[i-1] == 0)
            spojba[i]++;
        spojaa[i] = spojaa[i-2] + spojaa[i-1];
        if (kraj[i-2] == 0 && poc[i-1] == 0)
            spojaa[i]++;
        spojbb[i] = spojbb[i-2] + spojbb[i-1];
        if (kraj[i-2] == 1 && poc[i-1] == 1)
            spojbb[i]++;
        a[i] = a[i-2] + a[i-1];
        b[i] = b[i-2] + b[i-1];
    }

    for (ACa=0; ACa<50; ACa++)
        for (ACb=0; ACb<50; ACb++)
            for (POCa=0; POCa<3; POCa++)
                for (POCb=0; POCb<3; POCb++)
                    for (KRAJa=0; KRAJa<3; KRAJa++)
                        for (KRAJb=0; KRAJb<3; KRAJb++)
                            if (Moze(ACa, ACb, POCa, POCb, KRAJa, KRAJb)) {
                                da = 1;
                                break;
                            }

    if (da)
        printf("%s\n%s\n", s1.c_str(), s2.c_str());
    else
        printf("Happy new year!\n");

    return 0;
}