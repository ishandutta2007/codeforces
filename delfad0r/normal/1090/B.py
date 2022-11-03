import re
import sys

t, b = sys.stdin.read().split(r'\begin{thebibliography}{99}')
b = [(re.search(r'\{(.*?)\}', l).groups()[0], l) for l in b.split('\n') if r'\bibitem' in l]
c = re.findall(r'\{(.*?)\}', t)
if c == [i for i, _ in b]:
    print('Correct')
else:
    print('Incorrect')
    print(r'\begin{thebibliography}{99}')
    print(*(s for j in c for i, s in b if i == j), sep = '\n')
    print(r'\end{thebibliography}')