n=input()
a=[*map(int,input().split())]
a[0]=a[1]*a[2]//int(input().split()[2])
print(*[int(_/a[0]**.5) for _ in a])