input()
print(' '.join(map(lambda a: str(((int(a) - 1) & ~1) + 1), input().strip().split())))