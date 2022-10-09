from sys import stdin
stdin.readline()
s = stdin.readline().strip().replace(" ", "")
print(max(map(lambda s: len(s), (s + s).split('0'))))