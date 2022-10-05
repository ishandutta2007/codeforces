import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int,input().split()))

def gcd(a, b):  
    while b:
        a, b = b, a%b
    return a

def gcdL(l):
    while len(l) != 1:
        a = l.pop()
        b = l.pop()
        l.append(gcd(a,b))
    return l[0]

M = max(a)
l2 = [M - i for i in a if i != M]
tot = sum(l2)
small = gcdL(l2)

print(tot//small, small)