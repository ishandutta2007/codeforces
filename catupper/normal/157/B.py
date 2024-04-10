from math import pi
a=input()
b=map(int,raw_input().split())

b.sort()

b=map(lambda x:x*x,b)

print pi*(sum(b[::-2])-sum(b[-2::-2]))